//
// Copyright © 2021 Rodrigo Pelissier. All rights reserved.
//
// This file is part of La Weá Interpreter (C++)
//
// La Weá Interpreter (C++) is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.
//

#include "la_weá_interpreter.hpp"
#include "la_weá_code_parser.hpp"
#include "la_weá_exception.hpp"
#include "la_weá_expression.hpp"
#include "la_weá_context.hpp"
#include "utf_utils.hpp"

#include <iostream>
#include <fstream>

#if defined(_WIN64)
	#include <windows>
#endif

la_weá_interpreter::la_weá_interpreter() = default;
la_weá_interpreter::~la_weá_interpreter() = default;

void la_weá_interpreter::interpret(const char *file_path) {
	parse_code(get_code(file_path));
	run();
}

void la_weá_interpreter::parse_code(const std::u32string &code) {
	try {
		program = (la_weá_code_parser (code)).parse();
	} catch (la_weá_exception &e) {
		exit_with_error_message(std::string (e.what()));
	}
}

void la_weá_interpreter::run() {
	std::cout.setf(std::ios::unitbuf);

	la_weá_context *ctx = new la_weá_context;

	try {
		program->interpret(ctx);
		delete ctx;
	} catch (la_weá_exception &e) {
		delete ctx;
		exit_with_error_message(std::string (e.what()));
	}
}

void la_weá_interpreter::exit_with_error_message(const std::string &err_msg) const {
	print_error_in_red(err_msg.length() != 0 ? err_msg : "Error interno");
	std::exit(EXIT_FAILURE);
}

#if !defined(_WIN64)
	inline void la_weá_interpreter::print_error_in_red(const std::string &err_msg) const {
		std::cerr << "\x1b[1;31m" << err_msg << "\x1b[0m\n";
	}
#else
	void la_weá_interpreter::print_error_in_red(const std::string &err_msg) const {
		WCHAR utf16_buffer[err_msg.length() + 1];

        short utf16_buffer_len = MultiByteToWideChar(
        	CP_UTF8,
        	0,
        	err_msg.c_str(),
        	err_msg.length(),
        	utf16_buffer,
        	sizeof(utf16_buffer)
        );

        utf16_buffer[utf16_buffer_len] = L'\n';

        HANDLE error_handle = GetStdHandle(STD_ERROR_HANDLE);

        CONSOLE_SCREEN_BUFFER_INFO console_info;
        GetConsoleScreenBufferInfo(error_handle, &console_info);

        WORD saved_attributes = console_info.wAttributes;

        SetConsoleTextAttribute(error_handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
        WriteConsoleW(error_handle, utf16_buffer, utf16_buffer_len + 1, NULL, NULL);
        SetConsoleTextAttribute(error_handle, saved_attributes);
	}
#endif

std::u32string la_weá_interpreter::get_code(const char *file_path) const {
	std::ifstream is (file_path);

	if (!is) {
		file_open_error_exit();
	}

	is.seekg(0, is.end);
	std::streampos utf8_code_len = is.tellg();
	is.seekg(0, is.beg);

	std::string utf8_code (utf8_code_len, ' ');
	is.read(&utf8_code[0], utf8_code_len);

	return utf_utils::utf8_str_to_utf32(std::u8string((const char8_t *)utf8_code.data()));
}

void la_weá_interpreter::file_open_error_exit() const {
	switch (errno) {
		case EACCES:
			exit_with_error_message("No tenís permiso pa’ abrir la weá");
		case ENOENT:
			exit_with_error_message("No existe la weá, pos, wn");
		default:
			exit_with_error_message("");
	}
}
