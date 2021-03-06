#include <cmath>
#include <ctime>
#include "utils.h"
#include "graph.h"
#include "assert.h"

double Utils::m_seed = 0.0;

void Utils::setSeed()
{
	Utils::m_seed = fabs(fmod(123456789.0, 2147483647.0));
}

double Utils::random() {
	double a = 16087.0;
	double m = 2147483647.0;
	double q = 127773.0;
	double r = 2836.0;

	double lo, hi, test;

	hi = ceil(m_seed/q);
	
	lo = m_seed - q * hi;
	
	test = a * lo - r * hi;
	if (test < 0.0) {
		m_seed = test + m;
	} else {
		m_seed = test;
	}
	
	return m_seed / m;
}

double Utils::granularity()
{
	double t0;
	double t1;
	
	t0 = (double) clock();
	t1 = (double) clock();
	
	while (t1 == t0) {
		t1 = (double) clock();
	}
	
	return (t1-t0)/CLOCKS_PER_SEC;
}

int Utils::calcolaRipTara(int d, double tMin)
{
	int i;
	int rip = 1;
	
	clock_t t0 = 0;
	clock_t t1 = 0;
	
	while (t1-t0 <= tMin) {
		rip = rip*2; 								// stima di rip con crescita esponenziale
		Graph * list[rip];
		t0 = clock();
		for (i=0;i<rip;i++) {
			list[i] = Graph::generateRandomGraph(d);
		}
		t1 = clock();
		for(int j=0;j<rip;j++){
			delete list[j];
		}
	}
	// ricerca esatta del numero di ripetizioni per bisezione
	// approssimiamo a 5 cicli
	int max = rip;
	int min = rip/2;
	int cicliErrati = 5;
	while (max-min >= cicliErrati) {
		rip = (max + min)/2; 						// valore mediano
		Graph * list[rip];
		t0 = clock();
		for (i=0;i<rip;i++) {
			list[i] = Graph::generateRandomGraph(d);
		}
		t1 = clock();
		for(int j=0;j<rip;j++){
			delete list[j];
		}
		if (((double)(t1-t0))/CLOCKS_PER_SEC <= tMin) {
			min = rip;
		} else {
			max = rip;
		}
	}
	return max;
}

int Utils::calcolaRipLordo(int d, double tMin)
{
	int i;
	int rip = 1;
	
	clock_t t0 = 0;
	clock_t t1 = 0;
	
	while (t1-t0 <= tMin) {
		rip = rip*2;							// stima di rip con crescita esponenziale
		Graph * list[rip];
		t0 = clock();
		for (i=0;i<rip;i++) {
			list[i] = Graph::generateRandomGraph(d);
			//Graph * test1 = Graph::generateRandomGraph(d);
			//delete test1;
			Graph::minimumEdgesNeededToRoot(list[i]);
			Graph::generateShortestPathTree(list[i]);
		}
		t1 = clock();
		
		//clearing data
		for(int j=0;j<rip;j++)
		{
			delete list[j];
		}
		
	}
	// ricerca esatta del numero di ripetizioni per bisezione
	// approssimiamo a 5 cicli
	int max = rip;
	int min = rip/2;
	int cicliErrati = 5;
	while (max-min >= cicliErrati) {
		rip = (max + min)/2; 						// valore mediano
		Graph * list[rip];
		t0 = clock();
		for (i=0;i<rip;i++) {
			list[i] = Graph::generateRandomGraph(d);
			//Graph * test1 = Graph::generateRandomGraph(d);
			//delete test1;
			Graph::minimumEdgesNeededToRoot(list[i]);
			Graph::generateShortestPathTree(list[i]);
		}
		t1 = clock();
		
		//clearing data
		for(int j=0;j<rip;j++)
		{
			delete list[j];
		}
		
		if (((double)(t1-t0))/CLOCKS_PER_SEC <= tMin) {
			min = rip;
		} else {
			max = rip;
		}
	}
	return max;
}

double Utils::tempoMedioNetto(int d, double tMin)
{
	int i;

	int ripTara = calcolaRipTara(d, tMin);
	int ripLordo = calcolaRipLordo(d, tMin);
	
	clock_t t0 = 0;
	clock_t t1 = 0;
	
	Graph * list[ripTara];
	t0 = clock();
	for (i=0;i<ripTara;i++) {
		list[i] = Graph::generateRandomGraph(d);
	}
	t1 = clock();
	
	//clearing data
	for(int j=0;j<ripTara;j++)
	{
		delete list[j];
	}
	
	double ttara = ((double)(t1-t0))/CLOCKS_PER_SEC;
	
	Graph * list2[ripLordo];
	t0 = clock();
	for (i=0;i<ripLordo;i++) {
		list2[i] = Graph::generateRandomGraph(d);
		//Graph * test1 = Graph::generateRandomGraph(d);
		//delete test1;
		Graph::minimumEdgesNeededToRoot(list2[i]);
		Graph::generateShortestPathTree(list2[i]);
	}
	t1 = clock();
	
	//clearing data
	for(int j=0;j<ripLordo;j++)
	{
		delete list2[j];
	}
	
	double tlordo = ((double)(t1-t0))/CLOCKS_PER_SEC;
	
	//cout << "clock2: " << t0 << " " << t1 << endl;
	
	double tmedio = tlordo/(double)ripLordo - ttara/(double)ripTara;
	
	//cout << "tempi: " << tmedio << " " << tlordo << " " << ttara << endl;
	
	//assert(tmedio>0);
	
	return tmedio;
}

void Utils::misurazione(int d, double tMin)
{
	int n = 10;
	double za = 1.96;
	double DELTA;
	double t = 0.0;
	double sum2 = 0.0;
	int cn = 0;
	double delta;
	double m, e, s;
	int i;
	
	do {
		for (i=0;i<n;i++) {
			m = tempoMedioNetto(d, tMin);
			t += m;
			sum2 += pow(m, 2);
		}
		cn += n;
		e = t/cn;
		DELTA = e/10;
		s = sqrt(sum2/cn - pow(e,2) );
		delta = 1/sqrt(cn) * za * s;
	} while (delta>=DELTA);
	
	cout << e*1000 << " " << delta*1000 << endl;
	//printf("%f\n%f\n", e*1000, delta*1000);
	//return (e, delta)
}
