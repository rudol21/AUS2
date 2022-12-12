#pragma once
#include <iostream>
#include <string>
#include "UzemnaJednotka.h"
#include "Obec.h"
#include "Kriterium.h"

template<typename O, typename T>
class Filter
{
public:
	 virtual bool urciHodnotu(O& object,  Kriterium<O, T>& c) = 0;
};

template<typename O, typename T>
class Filter_fi: public Filter<O, T>
{
  public:
	  virtual bool urciHodnotu( O& o,  Kriterium<O, T>& c) override { return c.ohodnot(o) == alpha; }
	  virtual void setParameter(T param) { alpha = param; };
	  T dajParameter() { return alpha; };
  private: 
	  T alpha; 
};

template<typename O, typename T>
class Filter_FI: public Filter<O, T>
{
  public: 
	  virtual bool urciHodnotu( O& o,  Kriterium<O, T>& c) override { T result = c.ohodnot(o); 
	  if(alpha == -1)
		  return true;
	  return result >= alpha && result <= beta; }
	  virtual void setParametre(T paramA, T paramB) { alpha = paramA; beta = paramB; };
  private: T alpha; 
		   T beta; 
};

class filterNazov : public Filter_fi<UzemnaJednotka, std::string>
{
public:
	 virtual bool urciHodnotu(UzemnaJednotka& object,  Kriterium<UzemnaJednotka, std::string>& c) override
	{
		 if (dajParameter().compare("-1") == 0)
			 return true;
		return c.ohodnot(object).compare(dajParameter()) == 0;
	};
};
class filterVolici : public Filter_FI<UzemnaJednotka, int>
{
public:
	
private: int alpha;
		 int beta;

};
class filterUcast : public Filter_FI<UzemnaJednotka, double>
{
public:

private: int alpha;
		 int beta;

};

class filterPrislusnostObce : public Filter_fi<Obec, bool>
{
public:
	virtual bool urciHodnotu(Obec& object, Kriterium<Obec, bool>& c) override
	{
		return c.ohodnot(object);
	}; 

};

class filterMeno : public Filter_fi<Kandidat, std::string>
{
public:
	virtual bool urciHodnotu(Kandidat& object, Kriterium<Kandidat, std::string>& c) override
	{
		return c.ohodnot(object).compare(dajParameter()) == 0;
	};
};

template<typename O, typename T>
class VyberoveKriterium
{
public:
	virtual bool urciPrvok(O& object, Kriterium<O, T>& c) = 0;
};

template<typename O, typename T>
class VNajviacHlasov : public VyberoveKriterium<UzemnaJednotka, int>
{
public:
	virtual bool urciPrvok(O& o, Kriterium<O, T>& c) override { return o == alpha; }
	
};