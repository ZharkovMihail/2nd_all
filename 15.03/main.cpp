#include <cstdio>
#include <cstdlib>
#include <ctime>

class unit{
public:
	int atak;
	int hp;
	int amount;
	int hpreal=0;
	int buf=0;
	virtual int countdamag(){
		return atak*amount;
	};
	virtual void setdamage(int d){};
	virtual int countheal(){return 0;}
	virtual void setheal(int h){
		if(hpreal!=0){
			if(h>=(hp-hpreal)*amount){
			 	hpreal=hp;
			}else{
			 	hpreal=hpreal+h/amount;
			}
		} 
	}
	virtual int countbuf(){return 0;}
	int countbuf(){
		return buf*(rand%2);
	}
    virtual void healshild(){}
};
class single_shot: class unit{
public:
	void setdamage(int d){
		if(hp*amount<d){
			amount=0;
		}else{
			amount=amount-d/hp;
		}	                                                                         
	}
};
class multy_shot: class unit{
public:
	void setdemage(int d){
		if(hp*amount<d){
			amount=0;
			hpreal=0;
		}else{
			hpreal=hpreal-d/amount;
		}
	}
};
class healer: class unit{
public:
	int amount_heal;
	int countheal(){
		return amount_heal*amount;
	}
};
class s_healer: class healer,class single_shot{
public:
	amount_heal=5;
	hp=30;
	atak=5;
	buf=1;
	int countbuf(){
		return buf*(rand%2);
	}
};

class m_healer: class healer,class multy_shot{
public:
	amount_heal=4;
	hp=hpreal=25;
	atak=4;
};

class ataker_m: class unit, class multy_shot{
public:
    atak=6;
	virtual int countdamag(){
		return atak+atak*(rand%6);
	};
}; 

class tank: class unit{
public:
	int shildhpreal;
	int shildhp;
	void setdamage(int d){
	if(shildhp<=d/amount){
		shild=0;
		if(hpreal+shildhpreal<=d/amount){
			amount=hprealreal=0;
		}else{
			phreal-=d/amount;
		}
	}else{
		shildhpreal-=d/amount;
	}
};

class tank_randomshild: class tank{
public:
	shildhpreal=75;
	shildhp=75;
	hp=35;
	atak=7;
	int random=1;
	virtual void healshild(){
		random=random*(rand%50);
		if(shildhp<=shildhpreal+random){
			shildhpreal=shildhp;
		}else{
			shildhpreal+=random;
		}
	} 
};

class tank_partshild: class tank{
public:
	shildhpreal=50;
	shildhp=50;
	hp=50;
	atak=6;
	virtual void healshild(){
		if(shildhp<=shildhpreal+15){
			shildhpreal=shildhp;
		}else{
			shildhpreal+=15;
		}
	}; 
};

class tank_fullshild: class tank{
public:
	shildhpreal=25;
	shildhp=25;
	hp=50;
	atak=5;
	int buf=1;
	virtual void healshild(){
		shildhpreal=shildhp;
	}
	int countbuf(){
		return buf*(rand%2);
	} 
};

main(){
	srand(time(NULL));
}