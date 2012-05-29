#ifndef NSOBJCRUNTIME_H_
#define NSOBJCRUNTIME_H_
#pragma once

#if defined(__cplusplus)
#define FOUNDATION_EXTERN extern "C"
#else
#define FOUNDATION_EXTERN extern
#endif

#define rgb(...) RGB(...)

typedef bool BOOL;

#define YES (BOOL) 1
#define NO  (BOOL) 0

#define READ_ONLY  1
#define WRITE_ONLY 2
#define READ_WRITE 3

typedef int NSInteger;
typedef unsigned int NSUInteger;

template<typename TContainerType, typename TValueType, int TPropAccess = READ_WRITE>
class property {
  public:
    property() {
        this->_instance = NULL;
        this->set = NULL;
        this->get = NULL;
    }

    void setContainer(TContainerType* instance) {
        this->_instance = instance;
    }

    void setter(void (TContainerType::*pset)(TValueType value)) {
        if((TPropAccess == WRITE_ONLY) || (TPropAccess == READ_WRITE))
          this->set = pset;
        else
          this->set = NULL;
    }

    void getter(TValueType (TContainerType::*pget)()) {
        if((TPropAccess == READ_ONLY) || (TPropAccess == READ_WRITE))
         get = pget;
        else
          get = NULL;
    }

    TValueType operator =(const TValueType& value) {
        assert(_instance != NULL);
        assert(set != NULL);
        (_instance->*set)(value);    
        return value;
    }

    operator TValueType() {
        assert(_instance != NULL);
        assert(get != NULL);
        return (_instance->*get)();
    }

    TValueType operator->() {
        return (_instance->*get)();
    }

  private:
    TContainerType* _instance;
    void (TContainerType::*set)(TValueType value);
    TValueType (TContainerType::*get)();
};

// NSOBJCRUNTIME_H_
#endif