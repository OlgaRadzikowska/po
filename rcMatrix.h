#include <math.h>
#include <fstream>
using namespace std;
 

class CMatrix{
	private:
	 
	struct rcmatrix;
	rcmatrix* block;
	 
	public:
	class Cref;

	CMatrix();
	CMatrix(const CMatrix& cm);
	CMatrix(unsigned int nrows, unsigned int ncols, double var);
	CMatrix(unsigned int nrows, unsigned int ncols, double var1, double var2);
	CMatrix(fstream& fs);void write(unsigned int i, double* c);
	double* read(unsigned int i) const;
	double* operator[](unsigned int i )const;
	CMatrix& operator=(const CMatrix& asOp);
	CMatrix& operator=(double** co);
	~CMatrix();
	friend ostream & operator << (ostream & s, const CMatrix & matrix);
	friend CMatrix operator* (const CMatrix&, const CMatrix&);
	Cref operator[](unsigned int i);

};

struct CMatrix::rcmatrix
{
        double** data;
        unsigned int rows;
        unsigned int cols;
        unsigned int n;
 
};
 
