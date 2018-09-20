#!/usr/bin/php
<?PHP
	if ($argc < 2)
	return (0);
	$num = trim(preg_replace('/\s+/', ' ', $argv[1]));
	echo("$num\n");
?>