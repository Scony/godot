#include "gdscript_linter.h"

#include "modules/gdscript/gdscript_parser.h"

void GDScriptLinter::lint(const String &source_code) {
	GDScriptParser parser;
	Error err = parser.parse(source_code);
	if (err) {
		return;
	}
	const GDScriptParser::Node *node = parser.get_parse_tree();
	while (node != nullptr) {
		print_line("L:" + itos(node->line) + " C:" + itos(node->column) + " T:" + itos((int)node->type));
		node = node->next;
	}
}
