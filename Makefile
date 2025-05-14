all: hospital
hospital:
	g++ sraka/patient.cpp sraka/doctor.cpp sraka/department.cpp sraka/hospital.cpp sraka/menu.cpp sraka/main.cpp -Iinclude -o hospital
clean:
	rm -f hospital
