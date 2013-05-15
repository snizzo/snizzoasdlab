
class Graph{
	private:
		int connections [4][4];
		int d [4];
		int pi [4];
		//CODA q [4];
		char color [4];
	
	public:
		void setData();
		void bfs(int n); //this one prints shit
};
