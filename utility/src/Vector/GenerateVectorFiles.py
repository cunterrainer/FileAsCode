import os
import sys

use_PFO_API = True;
if len(sys.argv) > 1:
	if sys.argv[1].lower() == "false":
		use_PFO_API = False;

letters = [ "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "x", "y", "z" ]

def replaceBool(data):
	operator = ["++", "--"]
	for i in range(len(letters)):
		for k in range(len(operator)):
			to_replace = operator[k] + letters[i] + ";";
			data = data.replace(to_replace, "");

		to_replace = letters[i] + " / number,";
		data = data.replace(to_replace, "");

		to_replace = letters[i] + " / number";
		data = data.replace(to_replace, "");

		to_replace = letters[i] + " / v." + letters[i] + ","; 
		data = data.replace(to_replace, "");

		to_replace = letters[i] + " / v." + letters[i]; 
		data = data.replace(to_replace, "");
	
	operator = ["+=", "-=", "*=", "/="]
	for i in range(len(letters)):
		for k in range(len(operator)):
			to_replace = letters[i] + " " + operator[k] + " right." + letters[i] + ";";
			data = data.replace(to_replace, "");

			to_replace = letters[i] + " " + operator[k] + " number;";
			data = data.replace(to_replace, "");

	return data;

def replaceWithCast(data):
	operator = [ "/", "*", "+", "-", "+=", "-=", "*=", "/=" ]

	for i in range(len(letters)):
		for k in range(len(operator)):
			to_replace = letters[i] + " " + operator[k] + " v." + letters[i]; 
			cast_s = "cast(" + to_replace + ")";
			data = data.replace(to_replace, cast_s);

			to_replace = letters[i] + " " + operator[k] + " number";
			cast_s = "cast(" + to_replace + ")";
			data = data.replace(to_replace, cast_s);

			to_replace = letters[i] + " " + operator[k] + " right." + letters[i];
			cast_s = "cast(" + to_replace + ")";
			data = data.replace(to_replace, cast_s);

	return data;

def replaceOstream(data):
	for i in range(len(letters)):
		to_replace = "<< v." + letters[i];
		replace_with = "<< (int)v." + letters[i];
		data = data.replace(to_replace, replace_with);
	
	return data;

def addBytes(bytes_c):
	for i in range(len(bytes_c)):
		bytes_c[i] = "Bytes: " + bytes_c[i];

	return bytes_c;

def addInclude(include, file_type):
	for i in range(len(include)):
		include[i] = include[i] + file_type[i] + ".h";
	
	return include;

#types = ["int", "unsigned int", "bool", "char", "unsigned char", "short"
#		, "unsigned short", "long", "unsigned long", "long long", "unsigned long long", "float", "wchar_t", "long double"]

types = ["std::int32_t", "std::uint32_t", "bool", "std::int8_t", "std::uint8_t", "std::int16_t"
		, "std::uint16_t", "long", "unsigned long", "std::int64_t", "std::uint64_t", "std::float_t", "wchar_t", "long double"]

#vector_type = [ "i", "Ui", "b", "c", "Uc", "s", "Us", "l", "Ul", "ll", "Ull", "f", "Wc", "Ld"]
vector_type = [ "i32", "ui32", "b", "i8", "ui8", "i16", "ui16", "l", "Ul", "i64", "ui64", "f", "Wc", "Ld"]
#file_type = [ "i", "Ui", "B", "C", "Uc", "S", "Us", "L", "Ul", "LL", "Ull", "F", "Wc", "Ld"]
file_type = [ "i32", "Ui32", "B", "i8", "Ui8", "i16", "Ui16", "L", "Ul", "i64", "Ui64", "F", "Wc", "Ld"]
file_ending = [ ".h", ".cpp" ]
bytes_c = [ "4", "4", "1", "1", "1", "2", "2", "4", "4", "8", "8",  "4", "2", "8"]
range_c = [ "-2.147.483.648 to 2.147.483.647", "0 to 4.294.967.295", "true or false", "-128 to 127", "0 to 255", "-32.768 to 32.767"
		, "0 to 65.535", "-2.147.483.648 to 2.147.483.647", "0 to 4.294.967.295", "-9.223.372.036.854.775.808 to 9.223.372.036.854.775.807"
		, "0 to 18.446.744.073.709.551.615", "3.4E +/- 38  precision: (7 digits)", "0 to 65.535", "1.7E +/- 308  precision: (15 digits)"]
include = [ "Vector", "Vector", "Vector", "Vector", "Vector", "Vector", "Vector", "Vector", "Vector", "Vector", "Vector", "Vector", "Vector", "Vector"]
new_std_val_ar = [ "0", "0U", "false", "0", "0", "0", "0", "0L", "0Ul", "0ll", "0Ull", "0.f", "0", "0.0L"]

bytes_c = addBytes(bytes_c);
include = addInclude(include, file_type);

old_type = "std::double_t";
old_vec_type = "d";
old_std_val = "0.0";
old_bytes = "Bytes: 8";
old_range = "1.7E +/- 308  precision: (15 digits)";
old_include = "VectorD.h"

current_working_dir = os.getcwd();

for i in range(len(types)):
	new_type = types[i];
	new_vec_type = vector_type[i];

	new_std_val = new_std_val_ar[i];

	for k in range (len(file_ending)):
		os.chdir(current_working_dir);
		file = open("VectorD" + file_ending[k], 'r');
		data = file.read();
		file.close();

		data = data.replace(old_type, new_type);
		data = data.replace(old_std_val, new_std_val);

		for j in range(2,11):
			vec = "Vector" + str(j) + new_vec_type;
			old_vec = "Vector" + str(j) + old_vec_type;

			data = data.replace(old_vec, vec);

		try:	
			os.chdir(current_working_dir + "\\NewVectors");
		except:
			os.mkdir("NewVectors");
			os.chdir(current_working_dir + "\\NewVectors");

		data = data.replace(old_bytes, bytes_c[i]);
		data = data.replace(old_range, range_c[i]);
		data = data.replace(old_include, include[i]);

		if types[i] == "bool":
			data = replaceBool(data);

		if (types[i] == "bool" or types[i] == "unsigned char" or types[i] == "wchar_t" or types[i] == "unsigned short" or types[i] == "std::uint16_t" or types[i] == "std::uint8_t" or types[i] == "std::int8_t" or types[i] == "std::int16_t") and file_ending[k] == ".cpp":
			data = replaceWithCast(data);
			data = data[:13 + len(include[i])] + "#define cast(x) static_cast<" + types[i] + ">(x)\n\n" + data[13 + len(include[i]):];

		if use_PFO_API == False:
			data = data.replace("PFO_API", "");

		if types[i] == "wchar_t":
			data = data.replace("std::ostream&", "std::wostream&");

		if types[i] == "wchar_t" or types[i] == "unsigned char" or types[i] == "char":
			data = replaceOstream(data);

		file = open("Vector" + file_type[i] + file_ending[k], 'w');
		file.write(data);
		file.close();

# create template header classes
os.chdir(current_working_dir);

file = open("VectorD.cpp", 'r');
data = file.read();
file.close();

#data = data[:data.find("// Vector3d") - 4]
Vec = []
Vec.append(data[data.find("// Vector2d"):data.find("// Vector3d") - 4])
Vec.append(data[data.find("// Vector3d"):data.find("// Vector4d") - 4])
Vec.append(data[data.find("// Vector4d"):data.find("// Vector5d") - 4])
Vec.append(data[data.find("// Vector5d"):data.find("// Vector6d") - 4])
Vec.append(data[data.find("// Vector6d"):data.find("// Vector7d") - 4])
Vec.append(data[data.find("// Vector7d"):data.find("// Vector8d") - 4])
Vec.append(data[data.find("// Vector8d"):data.find("// Vector9d") - 4])
Vec.append(data[data.find("// Vector9d"):data.find("// Vector10d") - 4])
Vec.append(data[data.find("// Vector10d"):data.find("// End")])

classes = []

for i in range(len(Vec)):
	Vector = "Vector" + str(i + 2)
	Vec[i] = Vec[i].replace("\t", "\t\t")
	Vec[i] = Vec[i].replace("\t\t\t\t", "\t\t\t")
	Vec[i] = "\t\t" + Vec[i]
	Vec[i] = Vec[i].replace(Vector + "d::", "")
	Vec[i] = Vec[i].replace(Vector + "d", Vector)
	Vec[i] = Vec[i].replace(old_type, "T") # old_type == "std::double_t"
	Vec[i] = Vec[i].replace("// " + Vector, "// " + Vector + "\n" + "\t\tinline " + Vector + "() noexcept {}")

	# 4 spaces
	class_def = "\ttemplate<class T>\n"
	class_def += "\tclass Vector" + str(i + 2) + "\n\t{\n\tpublic:\n\t\tTEMPLATE_TYPE\n\tpublic:\n"
	class_def += Vec[i] + "\t};"
	classes.append(class_def)

classes[0] = classes[0].replace("TEMPLATE_TYPE", "T x, y;")
classes[1] = classes[1].replace("TEMPLATE_TYPE", "T x, y, z;")
classes[2] = classes[2].replace("TEMPLATE_TYPE", "T a, b, c, d;")
classes[3] = classes[3].replace("TEMPLATE_TYPE", "T a, b, c, d, e;")
classes[4] = classes[4].replace("TEMPLATE_TYPE", "T a, b, c, d, e, f;")
classes[5] = classes[5].replace("TEMPLATE_TYPE", "T a, b, c, d, e, f, g;")
classes[6] = classes[6].replace("TEMPLATE_TYPE", "T a, b, c, d, e, f, g, h;")
classes[7] = classes[7].replace("TEMPLATE_TYPE", "T a, b, c, d, e, f, g, h, i;")
classes[8] = classes[8].replace("TEMPLATE_TYPE", "T a, b, c, d, e, f, g, h, i, j;")


final_data = "#pragma once\n#include <iostream>\n\nnamespace util::math {\n\n"

for i in range(len(classes)):
	classes[i] = classes[i].replace("\t\t\t};", "\t};")
	if i != len(classes) - 1:
		final_data += classes[i] + "\n\n\n"
	else:
		final_data += classes[i] + "\n"

final_data += "\n\n"


file = open("VectorD.h", 'r');
data = file.read();
file.close();

ostream_funcs = data[data.find("// overloads for the << operator"):data.find("// End")]
ostream_funcs = "\t" + ostream_funcs
ostream_funcs = ostream_funcs.replace("inline static", "template<class T>\n\tinline static")

for i in range(len(classes)):
	ostream_funcs = ostream_funcs.replace("Vector" + str(i + 2) + "d", "Vector" + str(i + 2) + "<T>")

final_data += ostream_funcs + "END_OF_FINAL_DATA_PFO_PYTHON"
final_data = final_data.replace("\tEND_OF_FINAL_DATA_PFO_PYTHON", "}")

#final_data = replaceWithCast(final_data);
#final_data = final_data[:34] + "#define cast(x) static_cast<T>(x)\n\n" + final_data[34:];

os.chdir(current_working_dir + "\\NewVectors");
file = open("VectorT.h", 'w');
file.write(final_data);
file.close();