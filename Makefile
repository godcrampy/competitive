cpp_formatter=clang-format
cpp_formatter_options=-style=Google -i --verbose
file_pattern='.*\.\(cpp\|hpp\|cc\|cxx\|java\)'
exec_pattern='.*\.\(out\|class\)'

# Ignores archive/
format:
	@printf "Formatting C++ & Java files...\n"
	@find . -path ./archive -prune -o -regex $(file_pattern) -exec $(cpp_formatter) $(cpp_formatter_options) {} \;
	@printf "done\n"

# Formats everything
long:
	@printf "Formatting all files...\n"
	@find . -regex $(file_pattern) -exec $(cpp_formatter) $(cpp_formatter_options) {} \;
	@printf "done\n"

quick:
	@printf "Formatting problems + competitions...\n"
	@find problems/ competitions/ -regex $(file_pattern) -exec $(cpp_formatter) $(cpp_formatter_options) {} \;
	@printf "done\n"

problems-only:
	@printf "Formatting problems/...\n"
	@find problems/ -regex $(file_pattern) -exec $(cpp_formatter) $(cpp_formatter_options) {} \;
	@printf "done\n"

competitions-only:
	@printf "Formatting competitions/...\n"
	@find competitions/ -regex $(file_pattern) -exec $(cpp_formatter) $(cpp_formatter_options) {} \;
	@printf "done\n"

# Removes .out and .class files
clean:
	@printf "Cleaning executables...\n"
	@find . -regex $(exec_pattern) -type f -delete
	@printf "done\n"
