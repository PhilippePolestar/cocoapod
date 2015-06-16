#
#  Be sure to run `pod spec lint Peanut.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#


Pod::Spec.new do |s|
  s.name     = 'Peanut'
  s.version  = '0.0.1'
  s.summary  = 'Testing cocoapods'
  s.homepage = 'https://github.com/PhilippePolestar/cocoapod'
  s.authors  = {'Philippe PRAUD' => 'philippe.praud@polestar.eu'}
  s.source   = {:git => "git@github.com:PhilippePolestar/cocoapod.git"}
  s.license  = 'license'
  s.source_files  = '*.{a,h,framework}'
end
