#include "EOM_Exception.h"

EOM_Exception::EOM_Exception(const string& errMessage) // Реалізація конструктора винятка
:MyException(errMessage){
}