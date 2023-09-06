#ifndef _TENSOR_LIB_TENSOR_ASSERT_H_
#define _TENSOR_LIB_TENSOR_ASSERT_H_

#define ASSERT_FAILURE -1


#define TENSOR_ASSERT( condition ) \
        if(! condition ) { \
	  std::cerr << "Assertion Failure in " << __func__ << " at line " << __LINE__ <<std::endl; \
	  std::exit(ASSERT_FAILURE); \
	}

#define TENSOR_ASSERT( condition , message ) \
        if(! condition ) { \
          std::cerr << message << std::endl \
	  std::cerr << "Assertion Failure in " << __func__ << " at line " << __LINE__ <<std::endl; \
	  std::exit(ASSERT_FAILURE); \
	}

#endif
