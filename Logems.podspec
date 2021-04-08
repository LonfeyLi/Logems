#
# Be sure to run `pod lib lint Logems.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'Logems'
  s.version          = '0.9.0'
  s.summary          = 'A C++ library of collection log.'
  s.description      = <<-DESC
  一个收集日志的C++库
  DESC
  
  s.homepage         = 'https://github.com/LoneyLi/Logems'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'LoneyLi' => '397401886@qq.com' }
  s.source           = { :git => 'https://github.com/LoneyLi/Logems.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'
  s.platform     = :ios
  s.ios.deployment_target = "9.0"
  s.source_files = 'Logems/Classes/**/**'
  s.public_header_files = 'Logems/Classes/**/*.h'
#  s.subspec 'Frameworks' do |ss|
#    ss.source_files = 'Logems/Classes/Frameworks/**/*'
#  end
  #    s.subspec 'Headers' do |ss|
  #        ss.source_files = 'Logems/Classes/Headers/**/*'
  #    end
  # s.resource_bundles = {
  #   'Logems' => ['Logems/Assets/*.png']
  # }
  s.library = 'z'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
  s.requires_arc = true
  
end
