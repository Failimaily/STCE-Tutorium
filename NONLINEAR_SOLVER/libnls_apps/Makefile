EXE=$(addsuffix .exe, $(basename $(wildcard *.cpp)))
CPPC=g++ -g
CPPC_FLAGS=-Wall -Wextra -pedantic -Ofast -march=native
EIGEN_DIR=$(HOME)/Software/Eigen
DCO_DIR=$(HOME)/Software/dco
DCO_INC_DIR=$(DCO_DIR)/include
DCO_LIB_DIR=$(DCO_DIR)/lib
DCO_FLAGS=-DDCO_DISABLE_AUTO_WARNING
DCO_LIB=dcoc

BASE_DIR=$(HOME)/Documents/gitlab/e-learning/SP_CES/code
LIBLS_INC_DIR=$(BASE_DIR)/LINEAR_SYSTEM/libls/include
LIBNLS_INC_DIR=$(BASE_DIR)/NONLINEAR_SYSTEM/libnls/include
LIBNLS_APPS_INC_DIR=$(BASE_DIR)/NONLINEAR_SYSTEM/libnls_apps/include

all : $(EXE)
	./toy.exe
	./toy_dco.exe
	./lotka_volterra.exe
	./diffusion.exe 5

%.exe : %.cpp
	$(CPPC) $(CPPC_FLAGS) $(DCO_FLAGS) -I$(EIGEN_DIR) -I$(DCO_INC_DIR) -I$(LIBLS_INC_DIR) -I$(LIBNLS_INC_DIR) -I$(LIBNLS_APPS_INC_DIR) -L$(DCO_LIB_DIR) $< -o $@ -l$(DCO_LIB)

doc:
	cd doc && $(MAKE)

clean :
	cd doc && $(MAKE) clean
	rm -fr $(EXE) 

.PHONY: all doc clean

