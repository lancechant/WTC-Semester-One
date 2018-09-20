#!/usr/bin/php
<?PHP
if ($argc < 2)
	return(0);
date_default_timezone_set('CET');
// Arrays to convert dates and months into a number
$frmonths = array("Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre");
$months = array("01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12");

//Pass string into an array
$str = explode(" ", $argv[1]);
//Convert French months into a number
$j = 0;
while ($j < 12)
{
    if (strcasecmp($str[2], $frmonths[$j]) == 0)
        $str[2] = $months[$j];
    $j++;
}
if ($argc < 5)
{
    echo "Wrong Format\n";
    exit;
}
//Convert date array to a string
$date = "$str[3]"."-"."$str[2]"."-"."$str[1]"." "."$str[4]";

//Convert date to Unix Timestamp
$out = strtotime($date);

echo "$out\n";

$time = mktime ($date);

?>