/*

	(c) 2022 Arthur 'ArTDsL' Dias dos Santos Lasso.
	https://www.artdsl.space/

	* PROJECT MADE PUBLIC UNDER MIT LICENSE *

	- https://github.com/ArTDsL/ARTDSL-ICL-SAMP/


	##
		Name: ART_DEFINITIONS.inc
		Creation date: 2022/04/30
		Last Update: 2022/04/30
	##

*/
#if !defined PFWD
	#define PFWD::%0(%1)	forward %0(%1);\
							public %0(%1)
#endif
#if !defined INFINITY_LIFE
	#define INFINITY_LIFE (Float:0x7F800000)
#endif
#if !defined is_null
	#define is_null(%1) ((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif
#if PRESSED
	#define PRESSED(%0) \
    (((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))
#endif
