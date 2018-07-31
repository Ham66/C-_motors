#ifndef LINEAR_AXIS_H_
#define LINEAR_AXIS_H_

class linear_axis {
public:
	linear_axis(string path_to_device);
	void set_position(double position_to_set);
	int get_state();
private:
	Tango::DeviceProxy *linear_axis_device;	
	Tango::DeviceAttribute position_attribute;
	double position;
	string position_name = "Position";
	int state;
};
#endif


