#include <cstdio>

int main()
{
	int ch, cm, cs, sh, sm, ss, rh, rm, rs;
	scanf("%d:%d:%d", &ch, &cm, &cs);
	scanf("%d:%d:%d", &sh, &sm, &ss);

	int cT, sT, rT;
	cT = ch * 60 * 60 + cm * 60 + cs;
	sT = sh * 60 * 60 + sm * 60 + ss;

	if (cT > sT)
		sT += 24 * 60 * 60;

	rT = sT - cT;
	rh = rT / 3600, rT %= 3600;
	rm = rT / 60, rT %= 60;
	rs = rT;

	printf("%02d:%02d:%02d", rh, rm, rs);
}
