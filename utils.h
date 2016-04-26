#ifndef UTILS_H
#define UTILS_H

using namespace std;

class Utils {
    public:
		static double m_seed;
        static double random();
        static void setSeed();
        static double granularity();
        
        static int calcolaRipTara(int d, double tMin);
        static int calcolaRipLordo(int d, double tMin);
        static double tempoMedioNetto(int d, double tMin);
        static void misurazione(int d, double tMin);
};

#endif
