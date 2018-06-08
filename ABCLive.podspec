Pod::Spec.new do |s|
  s.name             = "ABCLive"
  s.version          = "1.0.0"
  s.summary          = "ABCLive."
  s.description      = "ABCPaiti of bing"
  s.homepage         = "http://www.abcpen.com"
  s.license          = 'MIT'
  s.author           = { "bing" => "bing@abcpen.com" }
  s.source           = { :git => 'https://github.com/BingO0o/ABCLiveKit.git' }
  s.platform         = :ios, '9.0'
  s.requires_arc     = true

  s.subspec 'ABCLiveCoreKit' do |sp|
    sp.public_header_files = 'ABCLiveSDK/ABCCoreKit.framework/Headers/ABCCoreKit.h'
    sp.source_files        = 'ABCLiveSDK/ABCCoreKit.framework/Headers/*.{h}'
    sp.vendored_frameworks = 'ABCLiveSDK/ABCCoreKit.framework'
    sp.pod_target_xcconfig = { 'ENABLE_BITCODE' => 'NO' }
  end

  s.subspec 'ABCLiveUIKit' do |sp|
    sp.public_header_files = 'ABCLiveSDK/ABCUIKit.framework/Headers/ABCLiveKit.h'
    sp.source_files        = 'ABCLiveSDK/ABCUIKit.framework/Headers/*.{h}'
    sp.vendored_frameworks = 'ABCLiveSDK/ABCUIKit.framework'
    sp.pod_target_xcconfig = { 'ENABLE_BITCODE' => 'NO' }
  end

end