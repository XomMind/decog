// team_b_52: diagonal offset helper (0x827d90) matched against COGMIND.exe (Beta 17.1).
// NOTE: placeholder names.
struct Point { int x; int y; void offset_40a2a0(int dx, int dy);	/* NOTE: placeholder name */ };
void teamb_offsetDiagonal827d90(Point *p, int dir, int dist, int side)	// 0x827d90
{
	switch (dir)
	{
		case 1:
			p->offset_40a2a0(dist,-dist);
			if (side == 0)
				break;
			if (side == 1)
				p->offset_40a2a0(0,-1);
			else
				p->offset_40a2a0(1,0);
			break;
		case 3:
			p->offset_40a2a0(dist,dist);
			if (side == 0)
				break;
			if (side == 1)
				p->offset_40a2a0(1,0);
			else
				p->offset_40a2a0(0,1);
			break;
		case 5:
			p->offset_40a2a0(-dist,dist);
			if (side == 0)
				break;
			if (side == 1)
				p->offset_40a2a0(0,1);
			else
				p->offset_40a2a0(-1,0);
			break;
		case 7:
			p->offset_40a2a0(-dist,-dist);
			if (side == 0)
				break;
			if (side == 1)
				p->offset_40a2a0(-1,0);
			else
				p->offset_40a2a0(0,-1);
			break;
	}
}
