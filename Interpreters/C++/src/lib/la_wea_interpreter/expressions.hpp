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

#ifndef EXPRESSIONS_HPP
#define EXPRESSIONS_HPP
	#include "expression.hpp"

	#include <string>
	
	namespace la_weá {
		class context;

		class maricón_expression: public expression {
			public:
				void interpret(context *) override;
		};

		class maraco_expression: public expression {
			public:
				void interpret(context *) override;
		};

		class weón_expression: public expression {
			public:
				void interpret(context *) override;
		};

		class aweonao_expression: public expression {
			public:
				void interpret(context *) override;
		};

		class maraca_expression: public expression {
			public:
				void interpret(context *) override;
		};

		class chucha_expression: public expression {
			public:
				void interpret(context *) override;
		};

		class puta_expression: public expression {
			public:
				void interpret(context *) override;
		};

		class pichula_expression: public expression {
			public:
				pichula_expression(long);

				void interpret(context *) override;
			private:
				long tula_idx;
		};

		class tula_expression: public expression {
			public:
				tula_expression(long);

				void interpret(context *) override;
			private:
				long pichula_idx;
		};

		class pico_expression: public expression {
			public:
				pico_expression(long);

				void interpret(context *) override;
			private:
				long tula_idx;
		};

		class ctm_expression: public expression {
			public:
				void interpret(context *) override;
		};

		class quéweá_expression: public expression {
			public:
				void interpret(context *) override;
		};

		class chúpala_expression: public expression {
			public:
				void interpret(context *) override;
		};

		class brígido_expression: public expression {
			public:
				void interpret(context *) override;
			private:
				std::string get_num_input() const;
				bool is_valid_num_input(const std::string &) const;
		};

		class perkin_expression: public expression {
			public:
				void interpret(context *) override;
		};

		class mierda_expression: public expression {
			public:
				void interpret(context *) override;
		};
	}
#endif
