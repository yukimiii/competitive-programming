	cout << ans << endl;
	while (l < r && a[l] != 1)
	{
		cnt[a[l]]--;
		l++;
	}
	cnt[a[l]]--;
	l++;