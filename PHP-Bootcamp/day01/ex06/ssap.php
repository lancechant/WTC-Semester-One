#!/usr/bin/php
<?PHP
$i = 1;
$flag == 0;
	if ($argc < 2)
		return(0);
while ($i < $argc)
{
	if (strstr($argv[$i], ' ') != NULL)
	{
		$arr = explode(" ", $argv[$i]);
		if ($flag == 1)
		{
			$k = 0;
			while ($k < sizeof($arr))
			{
				array_push($usort, $arr[$k]);
				$k++;
			}
		}
		else
		{
			$usort = $arr;
			$flag = 1;
		}
	}
	else
	{
		if ($flag == 1)
		{
			array_push($usort, $argv[$i]);
		}
		else
		{
			$usort = array($argv[$i]);
			$flag = 1;
		}
	}
	$i++;
}
sort($usort, 2);
$j = 0;
while ($j < sizeof($usort))
{
	echo $usort[$j]."\n";
	$j++;
}
?>