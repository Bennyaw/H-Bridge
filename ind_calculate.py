import math

def calculate_L(del_v,del_t):
	V=15
	del_i = del_v/0.2
	L = V/(del_i/del_t)
	return L/10**-6

def calculate_m(lr,lm):
        m=(lr+lm)/lr
        print("m value is ",m)
        return m

def calculate_fr(Lr,Cr):
        fr = 1/((2*3.141592)*math.sqrt(Lr*Cr))
        print("fr value is ",fr)
        return fr

def calculate_Fx(fs,Lr,Cr):
        fr = calculate_fr(Lr,Cr)
        Fx = fs/fr;
        print("Fx value is ",Fx)
        return Fx

def calculate_Rac(Np,Ns,Ro):
        Rac = (8/3.141592**2)* ((Np/Ns)** 2) * Ro
        print("Rac value is ",Rac)
        return Rac

def calculate_Q(Lr,Cr,Np,Ns,Ro):
        Rac = calculate_Rac(Np,Ns,Ro)
        Q = math.sqrt(Lr/Cr) / Rac
        print("Q value is ",Q)
        return Q

def get_LLC_Factors(fs,Lr,Cr,Np,Ns,Ro,Lm):
       calculate_Fx(fs,Lr,Cr)
       calculate_Q(Lr,Cr,Np,Ns,Ro)
       calculate_m(Lr,Lm)
       
def calculate_ResonantLLC_K(fs,Lr,Cr,Np,Ns,Ro,Lm):
        Fx = calculate_Fx(fs,Lr,Cr)
        m = calculate_m(Lr,Lm)
        Q = calculate_Q(Lr,Cr,Np,Ns,Ro)
        num = (Fx**2)*(m-1)
        in_sqrt = ((m*(Fx**2) - 1)**2) + (Fx**2)*(((Fx**2)-1)**2)*((m-1)**2)*(Q**2)
        den = math.sqrt(in_sqrt)
        K = num/den
        print("K value is ",K)
