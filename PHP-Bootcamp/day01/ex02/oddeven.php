#!/usr/bin/php
<?php

echo "Enter a number: ";
while ($line = fgets(STDIN))
{
	$num = trim(preg_replace('/\s+/', '', $line));
	if (is_numeric($num))	{
		if ($num % 2 == 0)
			echo "The number $num is even\n";
		else {
			echo "The number $num is odd\n";
		}

	}
	else	{
		echo "'$num' is not a number\n";
	}
	echo "Enter a number: ";
}
?>