/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:08:15 by sishizaw          #+#    #+#             */
/*   Updated: 2025/06/12 21:08:17 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : name_(name), isSigned_(false),
      gradeToSign_(gradeToSign), gradeToExecute_(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other)
    : name_(other.name_), isSigned_(other.isSigned_),
      gradeToSign_(other.gradeToSign_), gradeToExecute_(other.gradeToExecute_) {}

Form& Form::operator=(const Form& other) {
    if (this != &other)
        isSigned_ = other.isSigned_;
    return *this;
}

Form::~Form() {}

const std::string& Form::getName() const {
    return name_;
}

bool Form::getIsSigned() const {
    return isSigned_;
}

int Form::getGradeToSign() const {
    return gradeToSign_;
}

int Form::getGradeToExecute() const {
    return gradeToExecute_;
}

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > gradeToSign_)
        throw GradeTooLowException();
    isSigned_ = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Form \"" << f.getName()
       << "\", signed: " << (f.getIsSigned() ? "yes" : "no")
       << ", grade required to sign: " << f.getGradeToSign()
       << ", grade required to execute: " << f.getGradeToExecute();
    return os;
}
