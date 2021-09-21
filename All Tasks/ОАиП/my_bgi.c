#include <graphics.h>

int main(void)
{
	int graph_driver;
	int graph_mode;
	int graph_error_code;
	graph_driver= DETECT;
	initgraph(&graph_driver, &graph_mode, "N:\\common\\bgi");

	setcolor(5);
	line(10, 10, 50, 50);


	graph_error_code=graphresult();
	if(graph_error_code != grOk)
	{
		return 255;
	}
	delay(10000);
}