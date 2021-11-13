#include <utility>

  /**
   *  @brief  Forward an lvalue.
   *  @return The parameter cast to the specified type.
   *
   *  This function is used to implement "perfect forwarding".
   */
  template<typename _Tp>
    _Tp&&
    forward(typename std::remove_reference<_Tp>::type& __t)
    { return static_cast<_Tp&&>(__t); }

  /**
   *  @brief  Forward an rvalue.
   *  @return The parameter cast to the specified type.
   *
   *  This function is used to implement "perfect forwarding".
   */
  template<typename _Tp>
    _Tp&&
    forward(typename std::remove_reference<_Tp>::type&& __t)
    {
      static_assert(!std::is_lvalue_reference<_Tp>::value, "template argument"
		    " substituting _Tp is an lvalue reference type");
      return static_cast<_Tp&&>(__t);
    }

template <typename T, typename... Args>
T* factory(Args&&... args){
    return new T(forward<Args...>(args...));
}

/*
auto i = factory<int>(5);

template <typename int, typename... int>
int* factory(int&&... args){
    return new int(forward<int...>(args...));
}

template<typename int>
int&&
forward(int&& __t)
{
    return static_cast<int&&>(__t);
}
*/

/*
int a = 5;
auto i = factory<int>(a);

template <typename T, typename... int&>
T* factory(int&... args){
    return new T(forward<int&...>(args...));
}

template<typename int&>
int& &&
forward(int& __t)
{ return static_cast<int&>(__t); }
*/

int main(int argc, char* argv[]){
    int a = 5;
    auto i = factory<int>(a);
    return 0;
}