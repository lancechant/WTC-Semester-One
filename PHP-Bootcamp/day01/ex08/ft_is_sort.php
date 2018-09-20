#!/usr/bin/php
<?PHP
function ft_is_sort($tab)
{
	$sort = $tab;
	sort($sort, SORT_STRING);
	$flag = true;
	foreach($tab as $key=>$value)
	{
		if($value != $sort[$key])
			$flag = false;  
	}
	return $flag;
}
?>