#include <tango.h>
#include "linear_axis.h"

linear_axis::linear_axis(string path_to_device) {
	linear_axis_device = new Tango::DeviceProxy(path_to_device);
	position_attribute = linear_axis_device->read_attribute(position_name);
}

void linear_axis::set_position(double position_to_set) {
	try {
		//linear_axis_device->read_attribute(position_name);
		//cout << "hello" << endl;
		//position_attribute = linear_axis_device->read_attribute(position_name);
		Tango::DevVarDoubleArray *in = new Tango::DevVarDoubleArray();
		in->length(1);
		(*in)[0] = position_to_set;
		position_attribute << in;
		//cout << "position_attribute to set: " << position_attribute;
		linear_axis_device->write_attribute(position_attribute);
  	}
	catch (Tango::DevFailed &e) {
		Tango::Except::print_exception(e);
	}
	catch (CORBA::BAD_PARAM &e) {
		Tango::Except::print_exception(e);
	}
}

int linear_axis::get_state() {
	try {
		state = linear_axis_device->state();
		return state;
  	}
	catch (Tango::DevFailed &e) {
		Tango::Except::print_exception(e);
	}
}






