echo "**********************************"
echo "                                  "
echo "      0.exit"
echo "      1.new file"
echo "      2.write file"
echo "      3.read file"
echo "      4.modify file permissions"
echo "      5.view file permissions"
echo "                                  "
echo "**********************************"
echo "                                  "
read -p "Please input your choice(0-6): " number
echo "your input is $number"
if [ $number == 0 ]
then
	exit
elif [ $number == 1 ]
then
	echo "new file"
elif [ $number == 2 ]
then 
	echo "write file"
elif [ $number == 3 ]
then
	echo "read file"
elif [ $number == 4 ]
then
	echo "modify file"
elif [ $number == 5 ]
then
	echo "view file"
else
	echo "input error"
fi
