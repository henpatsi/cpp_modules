#!/bin/bash

echo "Creating class $1"

set -e
test -e $1.hpp && (echo "The .hpp file exists, exiting" && exit 1)
test -e $1.cpp && (echo "The .cpp file exists, exiting" && exit 1)

UPPERCASE=$(echo "$1" | awk '{print toupper($0)}')

HPP="#ifndef ${UPPERCASE}_HPP
# define ${UPPERCASE}_HPP

class $1
{
	public:
		${1}( void );
		${1}( const ${1}& );
		~${1}( void );
		${1}& operator=( const ${1}& );
};

#endif"

CPP="#include \"${1}.hpp\"

// CONSTRUCTOR

${1}::${1}(void)
{

}

// COPY

${1}::${1}(const ${1}& from)
{

}

// DESTRUCTOR

${1}::~${1}(void)
{

}

// OPERATOR

${1}& ${1}::operator=(const ${1}& from)
{

}

// MEMBER FUNCTIONS"

echo "$HPP" > $1.hpp
echo "$CPP" > $1.cpp

echo Done