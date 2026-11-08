# CPP05

A C++98 exercise series focused on exception handling, encapsulation, inheritance, and polymorphism. This project implements a small bureaucracy simulation where `Bureaucrat` objects interact with forms and execute restricted actions based on grade levels.

## Project overview

The repository is divided into four progressive exercises:

- `ex00` — `Bureaucrat` class and grade validation
- `ex01` — `Form` class and signing rules
- `ex02` — abstract form hierarchy and concrete form execution
- `ex03` — `Intern` factory for creating forms dynamically

## Learning goals

This project covers:

- class design and encapsulation
- operator overloading
- exception handling with custom exceptions
- inheritance and abstract base classes
- polymorphism
- object lifetime and ownership
- C++98-compatible implementation patterns

## Exercise breakdown

### ex00 — Bureaucrat

Implements a `Bureaucrat` class with:

- a name
- a grade from 1 (highest) to 150 (lowest)
- `incrementGrade()` and `decrementGrade()` methods
- custom exceptions for invalid grade values

### ex01 — Form

Adds a `Form` class with:

- a name
- a required signing grade
- an execution grade
- a signed state
- sign validation based on bureaucrat grade

### ex02 — Forms and execution

Introduces an abstract `Aform` base class and concrete forms:

- `ShrubberyCreationForm`
- `RobotomyRequestForm`
- `PresidentialPardonForm`

Each form has a specific execution requirement and performs an action when executed by a valid bureaucrat.

### ex03 — Intern factory

Implements an `Intern` class capable of creating the correct form type using a string name. This exercise focuses on factory patterns and form creation logic.

## Requirements

- C++ compiler with C++98 support
- GNU Make
- Linux/macOS environment

## Build and run

Each exercise has its own `makefile`.

### ex00

```bash
cd ex00
make
./bureaucrat
```

### ex01

```bash
cd ex01
make
./Form
```

### ex02

```bash
cd ex02
make
./Form
```

### ex03

```bash
cd ex03
make
./Form
```

## Make targets

Each exercise supports the common targets:

```bash
make
make clean
make fclean
make re
```

## Notes

- The project is written in pure C++98 style.
- Compilation flags include `-Wall -Wextra -Werror`.
- The repository demonstrates a progression from basic class behavior to a more complete object-oriented design.

## Repository structure

```text
CPP05/
├── ex00/
│   ├── Bureaucrat.cpp
│   ├── Bureaucrat.hpp
│   ├── main.cpp
│   └── makefile
├── ex01/
│   ├── Bureaucrat.cpp
│   ├── Bureaucrat.hpp
│   ├── Form.cpp
│   ├── Form.hpp
│   ├── main.cpp
│   └── makefile
├── ex02/
│   ├── Aform.cpp
│   ├── Aform.hpp
│   ├── Bureaucrat.cpp
│   ├── Bureaucrat.hpp
│   ├── PresidentialPardonForm.cpp
│   ├── PresidentialPardonForm.hpp
│   ├── RobotomyRequestForm.cpp
│   ├── RobotomyRequestForm.hpp
│   ├── ShrubberyCreationForm.cpp
│   ├── ShrubberyCreationForm.hpp
│   ├── main.cpp
│   └── makefile
├── ex03/
│   ├── Aform.cpp
│   ├── Aform.hpp
│   ├── Bureaucrat.cpp
│   ├── Bureaucrat.hpp
│   ├── Intern.cpp
│   ├── Intern.hpp
│   ├── PresidentialPardonForm.cpp
│   ├── PresidentialPardonForm.hpp
│   ├── RobotomyRequestForm.cpp
│   ├── RobotomyRequestForm.hpp
│   ├── ShrubberyCreationForm.cpp
│   ├── ShrubberyCreationForm.hpp
│   ├── main.cpp
│   └── makefile
└── README.md
```

## License

This project is for educational use and follows the course assignment structure.
