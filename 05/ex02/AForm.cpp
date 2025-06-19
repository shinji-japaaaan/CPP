/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:16:40 by sishizaw          #+#    #+#             */
/*   Updated: 2025/06/12 21:16:42 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : name_(name), isSigned_(false),
      gradeToSign_(gradeToSign), gradeToExecute_(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : name_(other.name_), isSigned_(other.isSigned_),
      gradeToSign_(other.gradeToSign_), gradeToExecute_(other.gradeToExecute_) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        isSigned_ = other.isSigned_;
    }
    return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const { return name_; }
bool AForm::getIsSigned() const { return isSigned_; }
int AForm::getGradeToSign() const { return gradeToSign_; }
int AForm::getGradeToExecute() const { return gradeToExecute_; }

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > gradeToSign_)
        throw GradeTooLowException();
    isSigned_ = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "AForm not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "AForm \"" << f.getName() << "\", signed: " << std::boolalpha
       << f.getIsSigned() << ", grade to sign: " << f.getGradeToSign()
       << ", grade to execute: " << f.getGradeToExecute();
    return os;
}
