cc_library(
	name = "lib-funcs",
	srcs = [
		"functions.cc",
		"factorial.cc",
	],
	hdrs = [
		"functions.h",
		"factorial.h"
	]
)


cc_test(
	name = "math_test",
	srcs = [
		"main_test.cc",
		"main_test.h",
	],
	deps = [
		"@com_google_googletest//:gtest_main",
		":lib-funcs"
	],
)


cc_test(
	name = "vector",
	srcs = [
		"test_fixtures.cc"
	],
	deps = [
		"@com_google_googletest//:gtest_main",
	],
)
