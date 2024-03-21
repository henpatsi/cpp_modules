#!/bin/bash

echo "Creating class $1"

set -e
test -e $1.hpp && (echo "The file exists and will not be overwritten" && exit 1)

UPPERCASE=$(echo "$1" | awk '{print toupper($0)}')

CLASS="#ifndef ${UPPERCASE}_HPP
# define ${UPPERCASE}_HPP

class $1
{
	${1}(void);
	${1}(const ${1}&);
	~${1}(void);
	${1} & operator = (const ${1}&);
};

#endif"

echo "$CLASS" > $1.hpp

echo Done