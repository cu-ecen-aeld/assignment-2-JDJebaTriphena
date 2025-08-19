if [ $# -eq 2 ]
then
	if [ -d $1 ]
	then
		echo "Directory found"
		total_matches=$(grep -o $2 $1/* | wc -l)
		total_files=$(grep -l $2 $1/* | wc -l)
		echo "The number of files are $total_files and the number of matching lines are $total_matches"
		exit 0

	else
		echo "$1 not a directory"
		exit 1
	fi
else
	echo "Insufficient args"
	exit 1
fi
