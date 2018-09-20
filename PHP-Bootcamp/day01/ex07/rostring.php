#!/usr/bin/php
<?PHP
if ($argc < 2)
return (0);
$str = trim(preg_replace('/\s\s+/', ' ', str_replace("\n", " ", $argv[1])));
$arr = explode(" ", $str);
$i = 1;
while ($i < sizeof($arr))
{
	echo($arr[$i]. " ");
	$i++;
}
echo $arr[0]. "\n";
?>