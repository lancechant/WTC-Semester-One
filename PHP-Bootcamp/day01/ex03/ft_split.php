#!/usr/bin/php
<?php

	function ft_split($str)
	{
		$r = explode(" ", $str);
		sort($r);
		foreach ($r as $key)
		{
			if (!empty($key))
				$ret[] = $key;
		}
		unset($r);
		return ($ret);
	}
?>