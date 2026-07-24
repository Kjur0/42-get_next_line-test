#/bin/sh

GNL_DIR=get_next_line

if [ -n "$1" ] && [ "$1" = "bonus" ]; then
	if [ -d $GNL_DIR ]; then
		make bonus > /dev/null
		if [ $? -ne 0 ]; then
			echo "Build failed."
			exit 1
		fi

		echo "Running tests..."

		echo "Running test 1..."
		cat "assets/stdin.txt" | ./get_next_line-test1 | awk '/\[----------\] Global test environment tear-down.*/,0'

		echo "Running test 2 (buffer = 1)..."
		cat "assets/stdin.txt" | ./get_next_line-test2 | awk '/\[----------\] Global test environment tear-down.*/,0'

		echo "Running test 3 (buffer = 42)..."
		cat "assets/stdin.txt" | ./get_next_line-test3 | awk '/\[----------\] Global test environment tear-down.*/,0'

		echo "Running test 4 (buffer > 2k)..."
		cat "assets/stdin.txt" | ./get_next_line-test4 | awk '/\[----------\] Global test environment tear-down.*/,0'

		statics=$(cat $GNL_DIR/get_next_line*_bonus.c | grep "static " | wc -l)
		if [ $statics -gt 1 ]; then
			echo "Too many static functions found in bonus files"
			exit 1
		fi
		echo "Found $statics static functions in bonus files: PASSED"
	fi
else
	if [ -d $GNL_DIR ]; then
		make > /dev/null
		if [ $? -ne 0 ]; then
			echo "Build failed."
			exit 1
		fi

		echo "Running tests..."

		echo "Running test 1..."
		cat assets/stdin.txt | ./get_next_line-test1 | awk '/\[----------\] Global test environment tear-down.*/,0'

		echo "Running test 2 (buffer = 1)..."
		cat assets/stdin.txt | ./get_next_line-test2 | awk '/\[----------\] Global test environment tear-down.*/,0'

		echo "Running test 3 (buffer = 42)..."
		cat assets/stdin.txt | ./get_next_line-test3 | awk '/\[----------\] Global test environment tear-down.*/,0'

		echo "Running test 4 (buffer > 2k)..."
		cat assets/stdin.txt | ./get_next_line-test4 | awk '/\[----------\] Global test environment tear-down.*/,0'
	fi
fi
