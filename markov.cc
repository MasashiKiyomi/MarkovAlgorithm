#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

typedef struct {
  std::string src;
  std::string dst;
  bool exit{false};
} command;

void remove_space_and_comment(std::string& str) {
  str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
  int p = str.find("#");
  if (p != std::string::npos)
    str.replace(p, str.size()-p, "");
}

void read_com(std::istream& in, std::vector<command>& com) {
  std::string  s;
  while (std::getline(in, s)) {
    std::string t {s};
    remove_space_and_comment(s);
    if (s == "")
      continue;

    command  c;
    int  i;
    for (i = 0; i < s.size() && s[i] != ':'; i++) {
      if (s[i] != ' ' && s[i] != '\t')
	c.src.push_back(s[i]);
    }
    if (i == s.size()) {
      std::cerr << "Can't understand the command > " << t << "\n";
      continue;
      //exit(EXIT_FAILURE);
    }
    if (s[++i] == ':') {
      c.exit = true;
      i++;
    }
    for ( ; i < s.size(); i++) {
      if (s[i] == ':') {
	std::cerr << "Can't understand the command > " << t << "\n";
	exit(EXIT_FAILURE);
      }
      if (s[i] != ' ' && s[i] != '\t')
	c.dst.push_back(s[i]);
    }
    com.push_back(c);
  }
}

typedef struct {
  bool  n_mode {false};
  bool  verbose_mode {false};
  std::string  executable_name;
  std::string  file_name;
  std::string  input_string;
} options;

void print_help(std::ostream& out, std::string exe) {
  out << exe << " [option(s)] <program_file> [option(s)] <input_string>\n";
  out << "options:\n";
  out << "\t-h, --help: print this help.\n";
  out << "\t-n: print the number of commands.\n";
  out << "\t-v, --verbose: print intermediate strings.\n";
}

void read_options(options& opt, std::vector<std::string>& args) {
  opt.input_string = args.back();
  args.erase(args.end()-1);

  if (args.size() <= 1 ||
      opt.input_string[0] == '-') {
    if (args.size() == 0)
      print_help(std::cerr, opt.input_string);
    else
      print_help(std::cerr, args[0]);
    exit(EXIT_FAILURE);
  }

  opt.executable_name = args[0];
  args.erase(args.begin());

  for (auto& arg : args) {
    if (arg == "-h" || arg == "--help") {
      print_help(std::cout, opt.executable_name);
      exit(EXIT_SUCCESS);

    } else if (arg == "-n") {
      opt.n_mode = true;

    } else if (arg == "-v" || arg == "--verbose") {
      opt.verbose_mode = true;

    } else if (arg[0] == '-') {
      std::cerr << "unknown option '" << arg << "'\n";
      std::cerr << "use -h option for help." << "\n";
      exit(EXIT_FAILURE);

    } else {
      if (opt.file_name != "") {
	print_help(std::cerr, opt.executable_name);
	exit(EXIT_FAILURE);
      }
      opt.file_name = arg;
    }
  }

  if (opt.file_name == "") {
    print_help(std::cerr, opt.executable_name);
    exit(EXIT_FAILURE);
  }
}

int main(int argc, char* argv[]) {
  options  opt;

  std::vector<std::string> args(argv, argv+argc);

  read_options(opt, args);

  std::ifstream in {opt.file_name};
  if (!in) {
    std::cerr << "Can't open " << opt.file_name << "\n";
    return 1;
  }
  std::vector<command> com;
  read_com(in, com);
  int  n = com.size();

  std::string  str = opt.input_string;

  bool  ret {false};
  bool  flag;
  do {
    if (opt.verbose_mode)
      std::cout << str << '\n';

    flag = false;
    for (auto itr = com.begin(); itr != com.end(); itr++) {
      command c = *itr;

      int  p = str.find(c.src);
      if (p != std::string::npos) {
	flag = true;
	str.replace(p, c.src.size(), c.dst);
	if (c.exit)
	  ret = true;
	break;
      }

    }

  } while (flag && !ret);

  if (!opt.verbose_mode || ret)
    std::cout << str << '\n';

  if (opt.n_mode)
    std::cout << n << '\n';

  return 0;
}
