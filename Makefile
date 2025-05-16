all: hospital
hospital:
	g++ patient.cpp doctor.cpp department.cpp hospital.cpp menu.cpp main.cpp -o hospital

clean:
	rm -f hospital
