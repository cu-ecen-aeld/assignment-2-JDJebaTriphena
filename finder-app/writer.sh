if [ $# -eq 2 ]
then
	path=$1
	name="${path##*/}"
	path="${pwd}""${path%/*}"
	echo $name $path
	if [ -d $path ]
	then
		cd $path
		echo $2 > $name
		exit 0
	else
		mkdir -p $path
		if [ -d $path ]
		then
			cd $path
			echo $2 > $name
			exit 0
		else
			exit 1
		fi
	fi

else
	echo "Insufficient args"
	exit 1
fi
