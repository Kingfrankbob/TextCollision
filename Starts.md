void Menu(int Selec, std::vector<std::string> MenuOptions, LedCanvas *canvas, Adafruit_PixelDust *sand) 
{
	for (int i = 0; i < MenuOptions.size(); i++)
	{
		std::stringstream ss;
		ss << MenuOptions[i];

		CollisionMatrix::Collision::printtxt(ss.str(), 3, i * 8, 0, 0, 0, 1, *sand, *canvas);

		if (Selec != i)
		{
			CollisionMatrix::Collision::printtxt(ss.str(), 3, i * 8, 255, 255, 255, 2, *sand, *canvas);
		}
		if (Selec == i)
		{
			int length = ss.str().length();
			length = length * 5;
			int iteration = i;
			for (int y = iteration * 8; y < iteration * 8 + 7; y++)
			{
				for (int i = 3; i < length; i++)
				{
					led_canvas_set_pixel(canvas, i, y, 0, 0, 0);
				}
			}
			CollisionMatrix::Collision::printtxt(ss.str(), 3, i * 8, 0, 0, 0, 2, *sand, *canvas);
		}
	}
}
