#include <math.h>
#include <fstream>
using namespace std;
 
class OutOfMem{};
 
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
		
		rcmatrix(){
                this->data=NULL;
                this->cols=0;
                this->rows=0;
                this->n=0;
        }
 
		
        rcmatrix(unsigned int nrows, unsigned int ncols, double var){
             try
             {
                this->data = new double*[nrows];
                for(unsigned int i=0;i<nrows;i++)
                this->data[i]=new double[ncols];
             }
             catch(...){
				throw OutOfMem();
             }
                 
            for(unsigned int i=0;i<nrows;i++)
            for(unsigned int j=0;j<ncols;j++)
            if(i==j)this->data[i][j]=var;
            else this->data[i][j]=0.0;
                 
            this->rows=nrows;
            this->cols=ncols;
            this->n=1;
        }
 
        rcmatrix(unsigned int nrows, unsigned int ncols, double var1, double var2){
			try
            {
                this->data = new double*[nrows];
                for(unsigned int i=0;i<nrows;i++)
                this->data[i]=new double[ncols];    
            }
			catch(...){
				throw OutOfMem(); 
			}
                         
			for(unsigned int i=0;i<nrows;i++)
			for(unsigned int j=0;j<ncols;j++)
			if(i==j)this->data[i][j]=var1;
			else this->data[i][j]=var2;
                         
			this->rows=nrows;
			this->cols=ncols;
			this->n=1;	
        }
		
		rcmatrix(fstream& fs){
			fs >> this->rows;
			fs >> this->cols;
	  
			try
			{
				this->data = new double*[this->rows];
				for(unsigned int i=0;i<this->rows;i++)
				this->data[i]=new double[this->cols];
			}
			catch(...)
			{
				throw OutOfMem();
			}
	  
			for(unsigned int i=0;i<this->rows;i++)
			for(unsigned int j=0;j<this->cols;j++){
			fs >> this->data[i][j];
			}
			this->n=1;
		}
 
};
 
