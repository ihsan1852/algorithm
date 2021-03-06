function [P_st1, P_st2, P_st3, P_st4,rem_cap] = fcn(D_st1, D_st2, D_st3, D_st4, W_st1, W_st2, W_st3, W_st4, cap)
    init_cap = cap;
    Demand=zeros(4,1);
    Weight=zeros(4,1);
    A_Power=zeros(4,1);
    n=0;
    
    Demand(1) = D_st1;
    Demand(2) = D_st2;
    Demand(3) = D_st3;
    Demand(4) = D_st4;
    
    Weight(1) = W_st1;
    Weight(2) = W_st2;
    Weight(3) = W_st3;
    Weight(4) = W_st4;  
    
    while(cap>0)
		for i=1:4
			if A_Power(i)<Demand(i)
				n=n+Weight(i);
                        end
        	end
		
		br=cap/n;
		cap=0;
		n=0;
		
		for i=1:4
			if(A_Power(i)<Demand(i))
                		A_Power(i)=A_Power(i) + Weight(i)*br;
				if(A_Power(i)>Demand(i))
					cap=cap+A_Power(i)-Demand(i);
					A_Power(i)=Demand(i);
        			 end
        		 end
        	end
    end
    rem_cap = (init_cap - (A_Power(1) + A_Power(2) + A_Power(3) + A_Power(4)))/1000; 
    P_st1 = A_Power(1)/1000; % W/1000 > kW
    P_st2 = A_Power(2)/1000;
    P_st3 = A_Power(3)/1000;
    P_st4 = A_Power(4)/1000;
end