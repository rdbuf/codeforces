set +x  # -x for verbose commands printing
set -e

export file=$1
export file_base_name=$2
export bin_file=./bin${file_base_name}

clang++ -Wall -Wextra -Wconversion -g -fsanitize=undefined -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls -DONLINE_JUDGE -DDEBUG -O1 \
	-Wno-sign-conversion -Wno-sign-compare -Werror=shadow -Werror=return-type -std=c++20 ${file} -o ${bin_file}
chmod +x ${bin_file}

mkdir -p ${file}.output
test_in=${file}.output/test.in
out_expected=${file}.output/test.out_expected
out_actual=${file}.output/test.out_actual

awk '/входные данныеСкопировать/{flag=1; next}/выходные данныеСкопировать/{flag=0} flag' $file > $test_in
awk '/выходные данныеСкопировать/{flag=1; next}/\*\*\* TEST CASES END \*\*\*\*\//{flag=0} flag' $file > $out_expected
${bin_file} < $test_in > $out_actual
printf " %.0s" {1..8}; printf "EXPECTED"; printf " %.0s" {1..56}; printf "ACTUAL\n"
sdiff <(nl $out_expected) <(nl $out_actual)
if [[ ${PIPESTATUS[0]} -eq 0 ]]; then echo PASSED; else echo MISMATCH; fi
