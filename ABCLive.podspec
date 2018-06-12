Pod::Spec.new do |s|
  s.name             = "ABCLive"
  s.version          = "1.0.1"
  s.summary          = "ABCLive."
  s.description      = "ABCLive of bing"
  s.homepage         = "http://www.abcpen.com"
  s.license          = 'MIT'
  s.author           = { "bing" => "bing@abcpen.com" }
  s.source           = { :git => 'https://github.com/BingO0o/ABCLiveKit.git' }
  s.platform         = :ios,'9.0'
  s.requires_arc     = true

  s.subspec 'ABCLiveCoreKit' do |sp|
    sp.public_header_files = 'ABCLiveSDK/ABCCoreKit.framework/Headers/ABCCoreKit.h'
    sp.source_files        = 'ABCLiveSDK/ABCCoreKit.framework/Headers/*.{h}'
    sp.vendored_frameworks = 'ABCLiveSDK/ABCCoreKit.framework'
    sp.pod_target_xcconfig = { 'ENABLE_BITCODE' => 'NO' }
  end

  s.subspec 'ABCLiveUIKit' do |sp|
    sp.public_header_files = 'ABCLiveSDK/ABCUIKit.framework/Headers/ABCUIKit.h'
    sp.source_files        = 'ABCLiveSDK/ABCUIKit.framework/Headers/*.{h}'
    sp.vendored_frameworks = 'ABCLiveSDK/ABCUIKit.framework'
    sp.pod_target_xcconfig = { 'ENABLE_BITCODE' => 'NO' }
  end

  s.subspec 'ABCLivePenKit' do |sp|
    sp.public_header_files = 'ABCLiveSDK/PenKit.framework/Headers/PenKit.h'
    sp.source_files        = 'ABCLiveSDK/PenKit.framework/Headers/*.{h}'
    sp.vendored_frameworks = 'ABCLiveSDK/PenKit.framework'
    sp.pod_target_xcconfig = { 'ENABLE_BITCODE' => 'NO' }
  end

end
