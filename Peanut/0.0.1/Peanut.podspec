Pod::Spec.new do |s|
  s.name     = 'Peanut'
  s.version  = '0.0.1'
  s.summary  = 'Testing cocoapods'
#  s.homepage = 'https://github.com/PhilippePolestar/cocoapod'
  s.homepage = 'http://naoclient:polestar@10.10.28.72:8082'
  s.authors  = {'Philippe PRAUD' => 'philippe.praud@polestar.eu'}
#  s.source   = {:git => "git@github.com:PhilippePolestar/cocoapod.git"}
  s.source   = {:git => "http://naoclient:polestar@10.10.28.72:8082"}
  s.license  = 'license'
  s.source_files  = '*.{a,h}'
end
