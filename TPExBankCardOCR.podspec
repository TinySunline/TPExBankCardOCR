#
# Be sure to run `pod lib lint TPExBankCardOCR.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'TPExBankCardOCR'
  s.version          = '0.0.3'
  s.summary          = '易道博识银行卡OCR'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
                   易道博识银行卡OCR(tiny平台的js扩展)
                       DESC

  s.homepage         = 'https://github.com/TinySunline/TPExBankCardOCR'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'bygd2014@sina.com' => 'bygd2014@sina.com' }
  s.source           = { :git => 'https://github.com/TinySunline/TPExBankCardOCR.git'}
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '7.0'

  s.source_files = 'TPExBankCardOCR/Classes/**/*'

  s.resource_bundles = {
    'TPExBankCardOCR' => ['TPExBankCardOCR/Assets/ExBankCardRes.bundle']
  }

  s.vendored_frameworks = 'TPExBankCardOCR/Assets/ExBankCardSDK.framework'

  #s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
