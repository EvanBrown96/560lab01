template <typename A>
ValueNotFound<A>::ValueNotFound(A err_value): std::logic_error("Value Not Found"), err_value(err_value){}

template <typename A>
A ValueNotFound<A>::getErrValue(){
  return err_value;
}
