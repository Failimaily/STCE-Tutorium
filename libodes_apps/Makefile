EXE=$(addsuffix .exe, $(basename $(wildcard *.cpp)))
CPPC=g++ 
CPPC_FLAGS=-Wall -Wextra -pedantic -Ofast -march=native
EIGEN_DIR=$(HOME)/Software/Eigen
DCO_DIR=$(HOME)/Software/dco_cpp
DCO_INC_DIR=$(DCO_DIR)/include
DCO_LIB_DIR=$(DCO_DIR)/lib
DCO_FLAGS=-DDCO_DISABLE_AUTO_WARNING
DCO_LIB=dcoc

BASE_DIR=$(HOME)/Test
LIBLS_INC_DIR=$(BASE_DIR)/LINEAR_SOLVER/libls/include
LIBNLS_INC_DIR=$(BASE_DIR)/NONLINEAR_SOLVER/libnls/include
LIBODES_INC_DIR=$(BASE_DIR)/libodes/include
LIBODES_APPS_INC_DIR=$(BASE_DIR)/libodes_apps/include

all : $(EXE)
	#./lotka_volterra_explicit_euler.exe 1 1000
	#./lotka_volterra_implicit_euler.exe 1 1000 1e-12
	#./diffusion_explicit_euler.exe 10 1 10000
	#./diffusion_implicit_euler.exe 10 1 10000 1e-5
	./linear_system_implicit_euler.exe 1 1000 1e-5


%.exe : %.cpp
	$(CPPC) $(CPPC_FLAGS) $(DCO_FLAGS) -I$(EIGEN_DIR) -I$(DCO_INC_DIR) -I$(LIBLS_INC_DIR) -I$(LIBNLS_INC_DIR) -I$(LIBODES_INC_DIR) -I$(LIBODES_APPS_INC_DIR) -L$(DCO_LIB_DIR) $< -o $@ -l$(DCO_LIB)

doc:
	cd doc && $(MAKE)

clean :
	cd doc && $(MAKE) clean
	rm -fr $(EXE) 

.PHONY: all doc clean

